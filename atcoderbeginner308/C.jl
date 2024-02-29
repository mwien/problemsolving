N = parse(Int64, readline())
res = Vector{Tuple{Rational{Int64}, Int64}}()
for i = 1:N
	A, B = parse.(Int64, split(readline()))
	push!(res, (A // (A+B), N-i))
end
sort!(res)
reverse!(res)
for i = 1:N
	print(N-res[i][2])
	print(" ")
end
println()

