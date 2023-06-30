N, M = parse.(Int64, split(readline()))

res = 2*10^18

for i = 1:N
    X = ceil(Int, M / i)
    X <= N && (global res = min(res, i*X))
    i > X && break
end

if res == 2*10^18
    println(-1)
else
    println(res)
end

