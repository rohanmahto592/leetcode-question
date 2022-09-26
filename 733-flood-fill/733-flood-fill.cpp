class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int initial)
    {
        if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size() or image[sr][sc]!=initial)
        {
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,initial);
         dfs(image,sr,sc+1,color,initial);
         dfs(image,sr+1,sc,color,initial);
         dfs(image,sr,sc-1,color,initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        if(initial==color)
        {
            return image;
        }
        dfs(image,sr,sc,color,initial);
        return image;
        
    }
};