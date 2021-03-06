function tst_match(p, t)
   local r   = match(p, t)
   assert(r)
   print("--------------")
   for i = 1, #r do
      print("  #" .. i .. " := " .. tostring(r[i]))
   end
end

local env = environment()
local N   = Const("N")
local f   = Const("f")
local a   = Const("a")
local b   = Const("b")
local x   = Local("x", N)
local y   = Local("y", N)
local V0  = mk_idx_meta(0, N)
local V1  = mk_idx_meta(1, N)
tst_match(f(V0, V0), f(a, a))
tst_match(f(V0, V1), f(a, b))
local F0  = mk_idx_meta(0, Pi(x, y, N))
tst_match(F0(x, y), f(x, f(x, y)))
assert(not match(F0(x, x), f(x, f(x, y))))
assert(not match(F0(x), f(x, y)))
local F0  = mk_idx_meta(0, Pi(x, N))
tst_match(Pi(x, y, F0(x)), Pi(x, y, f(f(x))))
tst_match(Fun(x, y, F0(x)), Fun(x, y, f(f(x))))
assert(not match(Pi(x, F0(x)), Pi(x, y, f(f(x)))))
