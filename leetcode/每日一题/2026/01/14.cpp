//https://leetcode.cn/problems/separate-squares-ii/description/?envType=daily-question&envId=2026-01-14

const int N = 50010;
    struct Segment{
        double y,x1,x2;
        int d;
        bool operator< (const Segment& t){
            return y < t.y;
        } 
    }seg[N * 2];

    struct Node{
        int l,r;
        int cnt;
        double len;
    }tr[N * 8];

class Solution {
public:
    vector<double> xs;

    void build(int u,int l,int r){
        tr[u] = {l,r,0,0};
        if(l != r){
            int mid = l + r >> 1;
            build(u << 1,l,mid);
            build(u << 1 | 1,mid + 1,r);
        }
    }

    int find(double y){
        return lower_bound(xs.begin(), xs.end(), y) - xs.begin();
    }

    void pushup(int u){
        if(tr[u].cnt){
            tr[u].len = xs[tr[u].r + 1] - xs[tr[u].l];
        }else if(tr[u].l != tr[u].r){
            tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
        }else tr[u].len = 0;
    }

    void modify(int u,int l,int r,int v){
        if(tr[u].l >= l && tr[u].r <= r){
            tr[u].cnt += v;
            pushup(u);
        }else {
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid)modify(u << 1,l,r,v);
            if(r > mid)modify(u << 1 | 1,l,r,v);
            pushup(u);
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        for(int i = 0,j = 0;i < n;i++){
            double x = squares[i][0];
            double y = squares[i][1];
            double r = squares[i][2];
            //左下角的点(x,y);
            //线段：y' = y 和 y' = y + r
            seg[j++] = {y,x,x + r,1};
            seg[j++] = {y + r,x,x + r,-1};
            //离散化：将x 和 x + r 放进xs，我们要将其离散化
            xs.push_back(x);xs.push_back(x + r);
        }
        //排序且去重
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        build(1,0,xs.size() - 2);
        sort(seg,seg + n * 2);
        double area = 0;

        vector<double> cnt;
        vector<double> width;

        for(int i = 0;i < n * 2;i++){
            if(i > 0){
                area += tr[1].len * (seg[i].y - seg[i - 1].y);
            }
            modify(1,find(seg[i].x1),find(seg[i].x2) - 1,seg[i].d);
            cnt.push_back(area);
            width.push_back(tr[1].len);
        }
        double halfAra = area / 2;
        //找到一半的位置
        double y = 0;
        double v = 0;
        double widthVal = 0;
        
        for(int i = 1;i < cnt.size();i++){
            if(cnt[i] >= halfAra && cnt[i - 1] <= halfAra){
                y = seg[i - 1].y;
                v = cnt[i - 1];
                widthVal = width[i - 1];
                break;
            }
        }
        return y + (area - v * 2) / (widthVal * 2.0);
    }
};