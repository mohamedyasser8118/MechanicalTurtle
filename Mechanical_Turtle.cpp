#include <iostream>
using namespace std;
int position(int input,int pos){
    if(input==3){
        pos= (pos+1)%4;
    }
    else if(input==4){
        pos= (pos+3)%4;
    }
    return pos;
}

void modifay (int arr[50][50],int *row,int *col,int pos,int point,int steps){
    switch(pos){
        case 0:
        for(int i=0;i<steps;i++){
            arr[*row][(*col)++]=point;
        }
            break;
        case 1:
        for(int i=0;i<steps;i++){
            arr[(*row)++][*col]=point;
        }
            break;
        case 2:
        for(int i=0;i<steps;i++){
           arr[*row][(*col)--]=point;
        }
            break;
        case 3:
        for(int i=0;i<steps;i++){
            arr[(*row)--][*col]=point;
        }
            break;
    }

}

void clean(int arr[50][50],int *row,int *col){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            arr[i][j]=0;
        }
    }
    *row = 0;
    *col = 0;
}

void print(int arr[50][50]){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if(arr[i][j]==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
   int arr[50][50]={0};
   int row=0;
   int col=0;
    int pos=0;
    int point=0;
    int input=0;
    cout<<"==========================================\n";
    cout<<"  1      - Pen up\n";
    cout<<"  2      - Pen down\n";
    cout<<"  3      - Turn right\n";
    cout<<"  4      - Turn left\n"; 
    cout<<"  5 <n>  - Move forward n spaces (e.g. 5 12)\n";
    cout<<"  6      - Print 50x50 floor\n"; 
    cout<<"  7      - Clean floor\n";
    cout<<"  9      - Exit program\n";
    cout<<"==========================================\n\n";
    while(true){
        cout<<"Enter command: ";
        cin>>input;
        switch(input){
    case 1:
        point=0;
        cout<<"-> Pen is now UP.\n";
        break;
    case 2:
        point=1;
        cout<<"-> Pen is now DOWN.\n";
        arr[row][col]=1;
        break;
    case 3:
        pos=position(input,pos);
        cout<<"-> Turned right."<<"row: "<<row<<" col: "<<col<<" pos: "<<pos<<endl;
        break;
    case 4:
        pos=position(input,pos);
        cout<<"-> Turned left."<<"row: "<<row<<" col: "<<col<<" pos: "<<pos<<endl;
        break;
    case 5:
        int steps;
        cin >> steps;
        modifay(arr,&row,&col,pos,point,steps);
        cout<<"-> Moved forward "<<steps<<" spaces. Current position: ("<<row<<", "<<col<<")\n";
        break;
    case 6:
        print(arr);
        break;     
     case 7:
        clean(arr,&row,&col);
        cout<<"-> Floor cleaned.\n";
        pos = 0;
        point = 0;
        break;  
}
   
        if(input==9){
            cout<<"-> Terminating turtle program.\n";
            break;
        }
    }
    return 0;
}


// void Turtule(int input,int arr[50][50],int row,int col,int pos,int point){
// switch(input){
//     case 1:
//         point=0;
//         cout<<"-> Pen is now UP.\n";
//         break;
//     case 2:
//         point=1;
//         cout<<"-> Pen is now DOWN.\n";
//         arr[row][col]=1;
//         break;
//     case 3:
//         pos=position(input,pos);
//         cout<<"-> Turned right."<<"row: "<<row<<" col: "<<col<<" pos: "<<pos<<endl;
//         break;
//     case 4:
//         pos=position(input,pos);
//         cout<<"-> Turned left."<<"row: "<<row<<" col: "<<col<<" pos: "<<pos<<endl;
//         break;
//     case 5:
//         int steps;
//         cin>>steps;
//         for(int i=0;i<steps;i++){
//             modifay(arr,row,col,pos,point,steps);
//         }    
//     case 6:
//         print(arr);
//         break;   
//     case 9:
//         cout<<"-> Terminating turtle program.\n";
//         break;     
// }
// }