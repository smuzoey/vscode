#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string>
#include<cstring>
using namespace std;
int result =0;
char sign1 = 'N';
int arcTail[100];
int arcHead[100];
int vexArr[100];
 
char biaodian[100]={'\0'};
int path[100]; 
string order_out = "";
 
typedef struct  POINT{
        int tail,head;  
        struct POINT *hlink, *tlink;    
        char biaodian; 
}POINT;
 
typedef struct POINT2{
        int data;
        bool visited;   
        POINT *fin, *fout;         
 
}POINT2;
 
typedef struct{
        POINT2 list[100]; 
        int vnum, anum;       
}Graph;
 
bool end1(string str){
     if(str == "END" || str == "end" || str == "EXT" || str == "ext")
            return true;
     return false;
}
 
int length(int num[]){
    int sum=0;
    for(int i=0; i<100; i++){
          if(num[i] != 0)
                sum++; 
          else
              break;
    }
    return sum;   
}
 
bool is_inArr(int ch[],int in){
     for(int i=0; i<length(ch); i++)
             if(in == ch[i])
                   return true;
     return false;
}
 
 
 
void insert(string str){
     int pos = length(vexArr);
     int i = length(arcTail);
     string _tail = str.substr(0,str.find('-'));
     string _head = str.substr(str.find('>')+1,str.find(',')-str.find('>')-1);
     char _biaodian = str[str.size()-1];
     if(!is_inArr(vexArr, atoi(_tail.c_str())))
          vexArr[pos++] = atoi(_tail.c_str());
     if(!is_inArr(vexArr, atoi(_head.c_str())))
          vexArr[pos++] = atoi(_head.c_str());
     arcTail[i] = atoi(_tail.c_str());
     arcHead[i] = atoi(_head.c_str());  
     biaodian[i] = _biaodian;         
}
 
int LocateVex(Graph *G, int vertex){
    int j=0,k;
    for(k=0; k<length(vexArr); k++)
             if(G->list[k].data == vertex){
                   j = k;
                   break;                   
             }    
    return j;
}
 
void CreateGraph(Graph *G){
     int _tail, _head;
     POINT *arcTemp;
     G->vnum = G->anum =0;
     for(int i=0; i<length(vexArr); i++){
             (*G).list[i].data = vexArr[i];
             G->list[i].fin = NULL;
             G->list[i].fout = NULL;  
             G->vnum++;  
             G->list[i].visited = false;
     }     
 
     //初始化弧并构建十字链表
     for(int i=0; i<length(arcTail); i++){
             if(biaodian[i] == 'T')
                     result ++;
             _tail = LocateVex(G,arcTail[i]);
             _head = LocateVex(G,arcHead[i]);
             arcTemp = (POINT*)malloc(sizeof(POINT));
             arcTemp->tail = _tail;
             arcTemp->head = _head;
             arcTemp->tlink = (*G).list[_tail].fout;
             (*G).list[_tail].fout = arcTemp;
             arcTemp->hlink = (*G).list[_head].fin;
             (*G).list[_head].fin = arcTemp;
             arcTemp->biaodian = biaodian[i]; 
             G->anum++;                       
     } 
}
 
 
 
 
 
void display(Graph *G,int arr[]){
     char ch[10];
     int temp =0;
     char is_no = 'N';
     for(int i=0; i<length(arr)-1; i++){
             string Arc = "";
             temp = arr[i];
             snprintf(ch,sizeof(ch),"%d",temp);
             Arc += ch;
             Arc += ",";
             temp = arr[i+1];
             snprintf(ch,sizeof(ch),"%d",temp);
             Arc += ch;
             if(order_out.find(Arc) != order_out.npos) 
                      continue;
             else{
                 is_no = 'Y';
                 break;
             } 
             i += 1;     
     }
     if(is_no == 'Y'){
              memset(ch,0,10);
 
     for(int i=0; i<length(arr)-1; i++){
             temp = arr[i];
             snprintf(ch,sizeof(ch),"%d",temp);
             order_out += ch;
             order_out += ",";
     }
     memset(ch,0,10);
     snprintf(ch,sizeof(ch),"%d",arr[length(arr)-1]);
     order_out += ch;
     order_out += "|"; 
     }
}
 
int my_memset(int arr[],int _data){
     int pos = 0;
     int _length = length(arr);
     for(int i=0; i<_length; i++)
           if(_data == arr[i]){
                     pos = i;
                     break;
           }
     for(int i=pos+1; i<_length; i++)
             arr[i] = 0;  
     //display(arr); 
     return pos;  
}
void changeVisited(Graph *G,int arr[], int num){
     char is_find_ = 'N';
     int pos =0;
     for(int i=0; i<length(arr); i++){
             if(arr[i] == num){
                       is_find_ = 'Y';
                       i++;          
             }    
             if(arr[i] != 0)
                       if(is_find_ == 'Y'){    
                                pos = LocateVex(G,arr[i]);
                                G->list[pos].visited = false;
                       }
     }     
}
 
//有向图的深度非递归遍历 
void DFSTraverse(Graph G, int pos){
     POINT *p;
     POINT *Queue[100*100];
     int Vex[100]={0};
     int _len_=0;
     int queue = -1;
     int pointer = -1;
     p = G.list[pos].fout;
     path[++pointer] = G.list[pos].data;
     if(!p){
           display(&G,path);
           return;
     }
     while(p){ 
           if(!is_inArr(path,G.list[p->tail].data))
                  path[++pointer] = G.list[p->tail].data;
           if(p->biaodian != 'N'){ 
                       //若遇到先前遍历过的结点则直接走F就行，T不予考虑 
                  if(is_inArr(Vex,G.list[p->tail].data) && (!G.list[p->tail].visited)){
                            if(p->biaodian == 'T')
                                        p = p->tlink;
                  }
                  else{
                       if((p->biaodian == 'T') && (!G.list[p->tail].visited)){
                             Queue[++queue] = p;
                             p = p->tlink;
                       }
                       else if(p->biaodian == 'F')
                            Queue[++queue] = p->tlink; 
                       G.list[p->tail].visited = true;
                       if(!is_inArr(Vex,G.list[p->tail].data))
                            Vex[_len_++] = G.list[p->tail].data; 
                  }
           }
           if(is_inArr(path,G.list[p->head].data)){
                  path[++pointer] = G.list[p->head].data;  
                  if(queue >= 0){ 
                                display(&G,path);         
                                p = Queue[queue];
                                queue --; 
                                pointer = my_memset(path,G.list[p->tail].data);     
                                changeVisited(&G,Vex,G.list[p->tail].data);
                  }
                  //不加else会导致死循环，因为到最后一层的时候数组为空。直接把头结点加入到循环队列中 
                  else{  
                         display(&G,path); 
                         break;
                  }
                  continue;                                            
           }
           path[++pointer] = G.list[p->head].data;
           pos = LocateVex(&G,G.list[p->head].data);
           p = G.list[pos].fout;
           if(!p){
                if(queue >= 0){     
                      display(&G,path); 
                      p = Queue[queue];
                      queue --;  
                      pointer = my_memset(path,G.list[p->tail].data);
                      changeVisited(&G,Vex,G.list[p->tail].data);
                }
                else{
                     display(&G,path);
                     break;     
                }
           }
     }
}
 
int returnNum(string str,char ch){
    int sum =0;
    while(str.size()){
          int pos = str.find(ch);
          if(pos != str.npos){
               str = str.substr(pos+1);
               sum++; 
          }
          else 
               break;          
    }
    return sum+1;   
}
 
void remove_(string str){
     int pos = order_out.find(str);
     order_out.replace(pos,str.size()+1,"");     
}
 
bool my_compare(string str1,string str2){
     str1 += ",";
     str2 += ",";
     string temp1 = "";
     string temp2 = "";
     int pos1 = str1.find(',');
     int pos2 = str2.find(',');
     while(str1.size()){
              temp1 = str1.substr(0,pos1);
              temp2 = str2.substr(0,pos2);
              if(atoi(temp1.c_str()) > atoi(temp2.c_str()))
				  return true;  
              else if(atoi(temp1.c_str()) < atoi(temp2.c_str()))
                  return false;
              str1 = str1.substr(pos1+1);
              pos1 = str1.find(',');
              str2 = str2.substr(pos2+1);  
              pos2 = str2.find(',');                
     }     
}
 
void orderDisplay(string str){
     string ordered = "";
     string _str = str;
     string small = str;
     int small_num = 100;
     string temp = "";
     char end1 = 'N';
     int pos = str.find('|');
     while(str.size()){
     for(int i=0; i<_str.size(); i++){
           temp = _str.substr(0,pos);
           if(returnNum(temp,',') < small_num){
                        small = temp;
                        small_num = returnNum(temp,',');
           }
           else if(returnNum(temp,',') == small_num)
                 if(my_compare(small,temp)){
                              small = temp; 
                              small_num = returnNum(temp,',');
                 }
           if(end1 == 'N'){
                _str = _str.substr(pos+1);  
                pos = _str.find('|');
                if(pos != _str.npos)
                     continue;
                else{
                     pos = _str.size();
                     end1 = 'Y';     
                }
           } 
           else
               break;   
     }
     ordered += small;
     ordered += "|";
     int _pos = str.find(small);
     str.replace(_pos,small.size()+1,"");
     _str = small = str;
     small_num =100;
     pos = str.find('|');
     end1 = 'N';
     }     
     order_out = ordered;  
}
 
void coutResult(string str){
     int pos = str.find('|');
     string temp;
     while(str.size()){
              temp = str.substr(0,pos);
              cout << temp << endl;
              str = str.substr(pos+1);
              pos = str.find('|');                  
     }
}
 
void changeVexArr(int num){
     for(int i=0; i<length(vexArr); i++)
             if(vexArr[i] == num){
                   vexArr[i] = num*10 + 1;
                   vexArr[length(vexArr)] = num*10 + 2;
                   break;             
             }             
}
 
void CreatePath(string str){
     string _vertex = str.substr(0,str.find(','));
     string _condition = str.substr(str.find(',')+1);
     int _num = atoi(_vertex.c_str());
     int _T = 0,_F = 0,_in[100]={0};
     int l = length(arcTail);
     int l_l =0;
     changeVexArr(_num);  
     for(int i=0; i<l; i++)
                   if(arcHead[i] == _num)
                          _in[l_l++] = i;                    
     for(int j=0; j<l; j++){
                   if((biaodian[j] == 'F') && (arcTail[j] == _num))
                        _F = j;
                   else if((biaodian[j] == 'T') && (arcTail[j] == _num)) 
                        _T = j;                            
     }
     for(int i=0; i<l_l; i++)
                   arcHead[_in[i]] = _num*10+1;
     if(_condition == "AND"){   
           int _into = length(arcTail);
           arcTail[_F] = _num*10+1;   
           arcTail[_into] = _num*10+1;   
           arcHead[_into] = _num*10+2;
           biaodian[_into] = 'T';
           _into ++;
           arcTail[_T] = _num*10+2;
           arcTail[_into] = _num*10+2;
           arcHead[_into] = arcHead[_F];
           biaodian[_into] = 'F';
     }
 
     else if(_condition == "OR"){
 
           int _into = length(arcTail);
           arcTail[_T] = _num*10+1;
           arcTail[_into] = _num*10+1;
           arcHead[_into] = _num*10+2;
           biaodian[_into] = 'F';
           _into++;
           arcTail[_F] = _num*10+2;
           arcTail[_into] = _num*10+2;
           arcHead[_into] = arcHead[_T];
           biaodian[_into] = 'T';
     }
}
/*
void xianshi(){
    for(int i=0; i<length(vexArr); i++)
            cout << vexArr[i] << endl;
    for(int i=0; i<length(arcTail); i++)
            cout << arcTail[i] << "->" << arcHead[i] << "," << biaodian[i] << endl;     
}
*/
int main(){
    Graph G;
    int i=0;
    string temp ="";
	memset(arcTail,0,sizeof(arcTail));
	memset(arcTail,0,sizeof(arcHead));
	
	memset(arcTail,0,sizeof(vexArr));
    int _header = 0;
    getline(cin,temp);
 
    if(temp == "END")
            return 0;
    vexArr[i++] = atoi(temp.c_str());
    while(1){
             getline(cin,temp);
             if(temp == "EXT" || temp == "ext")
                   sign1 = 'Y';
             if(end1(temp)) 
                   break;
             insert(temp);        
    }
    if(sign1 == 'Y')
             while(1){
                      getline(cin,temp);
                      if(end1(temp))
                            break;
                      CreatePath(temp); 
             }
    CreateGraph(&G);
    DFSTraverse(G,LocateVex(&G,vexArr[0]));
    cout << "CC=" << returnNum(order_out,'|')-1 << endl;
    for(int i=0;i<10;i++)
    orderDisplay(order_out);
    coutResult(order_out);
	//while(1)
		//getchar();
    return 0;   
}
