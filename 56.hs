import Data.List

digs :: Integral x => x -> [x]
digs 0 = []
digs x = digs (x `div`10) ++ [x`mod`10]

list = [a^b | a<-[1..99], b<-[1..99] ]

l=[ sum (digs c) | c<-list]

maximum l
