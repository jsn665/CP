class DisjointSets{
    private int[] parents;
    private int[] groupSize;
    private int totalGroups;
    public DisjointSets(int N){
        totalGroups = N;
        parents = new int[totalGroups];
        groupSize = new int[totalGroups];
        for(int i = 0; i < totalGroups; i++){
            parents[i] = i;
            groupSize[i] = 1;
        }
    }

    public int find(int x){
        int root = x;
        while(parents[root] != root){
            root = parents[root];
        }
        while(parents[x] != root){
            int temp = parents[x];
            parents[x] = root;
            x = temp;
        }
        return root;
    }

    public void union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY){
            if(groupSize[rootX] < groupSize[rootY]){
                groupSize[rootY] += groupSize[rootX];
                parents[rootX] = rootY;
                groupSize[rootX] = 0;
            }
            else{
                groupSize[rootX] += groupSize[rootY];
                parents[rootY] = rootX;
                groupSize[rootY] = 0;
            }
            totalGroups--;
        }
    }

}
