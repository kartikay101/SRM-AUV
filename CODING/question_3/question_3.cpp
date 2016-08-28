//open README.txt before using the code
    #include<iostream>
    void input();  //takes input
    void display(); //displays input
    int test(); //tests validiy
    using namespace std ;
     
    int sud[9][9];  //input sudoku
    int main()
    {
    int x=1;
    input();
    display();
    x=test();
     
    if(x==1){
    cout<<"Valid SUDOKU";
    }
    else{
    cout<<"Invalid SUDOKU";
    }
     
    }
     
    void input(){
    for(int i=0;i<9;i++)
    {
    for(int j=0;j<9;j++)
    {
    cin>>sud[i][j];
    }
    //cout<<"\n\n";
    }
    }
    void display(){
    for(int i=0;i<9;i++)
    {
    for(int j=0;j<9;j++)
    {
    cout<<sud[i][j]<<" ";
    }
    cout<<"\n";
    }
    //cout<<"\n\n";
    }
     
    int test(){
    int a[]={0,0,0,0,0,0,0,0,0};
    int b[]={0,0,0,0,0,0,0,0,0};
    int f=0;
    for(int i=0;i<9;i++){ //checks rows for duplicates
    for(int j=0;j<9;j++){
    f=sud[i][j];
    if(f>0&&f<10){
    a[f-1]=a[f-1]+1;
    if(a[f-1]>1){
    return 0;
    }
    }
    else{
    return 0;
    }
    } //for ends
    a[0]=0;a[1]=0;a[2]=0;a[3]=0;a[4]=0;a[5]=0;a[6]=0;a[7]=0;a[8]=0;  //all array elements reset to 0;
    } //for ends
     
    for(int i=0;i<9;i++){  //checks columns for duplicates
    for(int j=0;j<9;j++){
    f=sud[j][i];
    if(f>0&&f<10){
    b[f-1]=b[f-1]+1;
    if(b[f-1]>1){
    return 0;
    }
    }
    else{
    return 0;
    }
    } //for ends
    b[0]=0;b[1]=0;b[2]=0;b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=0; //all array elements reset to 0;
    } //for ends
    return 1;
    }
