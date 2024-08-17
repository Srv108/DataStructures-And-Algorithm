void addEdge(int src,int des,bool bi_dir = true){
    graph[src].push_back(des);
    if(bi_dir){
        graph[des].push_back(src);
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> "<< "{ ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"}"<<endl;
    }
}
int main(){
    int v;
    cout<<"Enter no. of vertices  : ";
    cin>>v;

    graph.resize(v,list<int>());

    int e;
    cout<<"Enter no. of edges  : ";
    cin>>e;

    while(e--){
        int src,des;
        cin>>src>>des;
        addEdge(src,des,true);
    }
    
    display();
}