function solve(N, X, A)
	
end

N, M = parse.(Int64, split(readline()))
C = split(readline())
D = split(readline())
P = parse.(Int64, split(readline()))

price = Dict{String, Int64}()
for i = 1:M
	price[D[i]] = P[i+1]
end

res = 0
for i = 1:N
	if haskey(price, C[i])
		global res += price[C[i]]
	else 
		global res += P[1]
	end
end

println(res)
