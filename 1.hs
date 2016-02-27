main = putStrLn (show (muls 3 5 1000))

muls x y z =  sum muls_of_x_and_y
	where muls_of_x_and_y = [ x | x <- [x,2*x..z], x`mod`y /=0 ] ++
							[ y | y <- [y,2*y..z]] 

