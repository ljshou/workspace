/**
 * @file windows.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-18
 */

int calcOverlap(Rect A, Rect B) {
    int x = max(0, min(A.x2, B.x2) - max(A.x1, B.x1));
    int y = max(0, min(A.y2, B.y2) - max(A.y1, B.y1));
    return x * y;
}

int minOverlapping(vector<Rect> &rects, int W, int H, int w, int h) {
    if (rects.size() == 0) return 0;

    vector<int> x, y;
    x.push_back(0), x.push_back(H - h);
    y.push_back(0), y.push_back(W - w);

    for (int i = 0; i < rects.size(); i++) {
        if (rects[i].x1 - h >= 0) x.push_back(rects[i].x1 - h);
        if (rects[i].y1 - w >= 0) y.push_back(rects[i].y1 - w);
        if (rects[i].x2 + h <= H) x.push_back(rects[i].x2);
        if (rects[i].y2 + w <= W) y.push_back(rects[i].y2);
    }

    int overlap = h*w + 1;
    Rect r;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
            r.x1 = x[i], r.x2 = x[i] + h;
            r.y1 = y[j], r.y2 = y[j] + w;
            int o = 0;
            for (int k = 0; k < rects.size(); k++) {
                o += calcOverlap(r, rects[k]);
            }
            overlap = min(overlap, o);
        }
    }
    return overlap;
}

