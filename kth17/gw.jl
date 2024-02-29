function components(g, u, vis, comps)
	vis[u] && return
	vis[u] = true
	push!(last(comps), u)

	for v in g[u]
		components(g, v, vis, comps)
	end
end

function calcpair(c, pp, am) 
	sum = 0

	for i in eachindex(pp)
		sum += am[c[i], c[pp[i]]]
	end

	return sum /= 2
end

function findpairings(c, am, pp, mn)
	fst = -1
	for i in eachindex(c)
		pp[i] != 0 && continue
		fst = i
		break
	end
	if fst == -1 
		mn[1] = min(mn[1], calcpair(c, pp, am))
		return
	end
	for i in eachindex(c)
		pp[i] != 0 && continue
		i == fst && continue
		snd = i 
		pp[fst] = snd
		pp[snd] = fst
		findpairings(c, am, pp, mn)
		pp[fst] = 0
		pp[snd] = 0
	end
end

function minpairing(c, am)
	mn = [10^9]
	pp = zeros(Int64, length(c))
	findpairings(c, am, pp, mn)
	return first(mn)
end

function solve(comps, am)
	res = 0
	for c in comps 
		if length(c) % 2 != 0
			println("impossible")
			return
		end
		res += minpairing(c, am)
	end
	println(res)
end

n, m = parse.(Int64, split(readline()))

g = [Vector{Int64}() for _ = 1:n]
am = zeros(Int64, n, n)

for i = 1:m 
	p, q, c = parse.(Int64, split(readline()))
	am[p, q] = c 
	am[q, p] = c 
	push!(g[p], q)
	push!(g[q], p)
end

comps = []
vis = falses(n)

for u = 1:n
	vis[u] && continue
	push!(comps, Vector{Int64}())
	components(g, u, vis, comps)
end

solve(comps, am)
