#include<cstdio>
#include<cstring>

char s[100000+5];
int c[256], p[256], mx[256];

void init() { for(int i = 0; i < 256; ++i) p[i] = i; }
int get(int u) { return u == p[u] ? u : p[u] = get(p[u]); }

int main() {
    scanf("%s", s);
    for(int i = 0; s[i]; ++i) ++c[s[i]], ++mx[s[i]];
    init();
    for(int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        int x = get(s[i]), y = get(s[j]);
        if(x != y) {
            p[p[x]] = p[y]; c[y] += c[x];
            if(mx[x] > mx[y]) mx[y] = mx[x];
            c[x] = 0; mx[x] = 0;
        }
    }
    int res = 0;
    for(int i = 0; i < 256; ++i) res += c[i] - mx[i];
    printf("%d\n", res);
    return 0;
}
