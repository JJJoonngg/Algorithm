//
// Created by 김종신 on 2020/05/07.
//
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie {
    int cnt;
    bool finish;
    Trie *next[26];

    Trie() : finish(false), cnt(1) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }

    void insert(const char *key) {
        if (*key == '\0')
            finish = true;
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            else next[curr]->cnt++;

            next[curr]->insert(key + 1);
        }
    }

    int find(const char *key) {
        int curr = *key - 'a';
        if (*key == '?') {
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                if (next[i] != NULL)
                    cnt += next[i]->cnt;
            return cnt;
        }
        if (next[curr] == NULL) return 0;
        if (*(key + 1) == '?') return next[curr]->cnt;
        return next[curr]->find(key + 1);
    }
};
//출처: https://jason9319.tistory.com/129 [ACM-ICPC 상 탈 사람]

Trie *trie[10001];
Trie *rTrie[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);

    for (auto cur : words) {
        int len = cur.length();

        const char *c = cur.c_str();
        if (trie[len] == NULL) trie[len] = new Trie();
        trie[len]->insert(c);

        string cur2 = cur;
        reverse(cur2.begin(), cur2.end());

        const char *c2 = cur2.c_str();
        if (rTrie[len] == NULL) rTrie[len] = new Trie();
        rTrie[len]->insert(c2);
    }

    int idx = 0;
    for (auto cur : queries) {
        int len = cur.length();

        if (cur[len - 1] == '?') {
            const char *c = cur.c_str();
            if (trie[len] == NULL) {
                idx++;
                continue;
            } else {
                answer[idx] = trie[len]->find(c);
            }
        } else {
            string cur2 = cur;
            reverse(cur2.begin(), cur2.end());
            const char *c = cur2.c_str();
            if (rTrie[len] == NULL) {
                idx++;
                continue;
            } else {
                answer[idx] = rTrie[len]->find(c);
            }
        }
        idx++;
    }

    return answer;
}