#ans는 s부터 e까지 거쳐가는 정점의 목록
def d(s, e, tree):
    visit=[0]*(n+1)
    back=[0]*(n+1)
    ans=[]

    Q=deque([(s, 0)])
    while Q:
        v, prev=Q.popleft()
        if visit[v]: continue
        visit[v]=1
        back[v]=prev
        if v==e:
            break

        for nxt in tree[v]:
            Q.append((nxt, v))
    else:
        return []

    node=e
    while node!=0:
        ans.append(node)
        node=back[node]
    return ans[::-1]


#ans는 s에서부터 나머지 정점까지의 거리
def d(s, tree):
    visit=[0]*(n+1)
    ans=[-1]*(n+1)

    Q=[(0, s)]
    while Q:
        dis, v=heappop(Q)
        if visit[v]: continue
        visit[v]=1
        ans[v]=dis
        for nxt, dist in tree[v]:
            heappush(Q, (dis+dist, nxt))
    return ans
