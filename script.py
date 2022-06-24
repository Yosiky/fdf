import os

files = ['./test_maps/basictest.fdf',
'./test_maps/elem2.fdf',
'./test_maps/t1.fdf',
'./test_maps/100-6.fdf',
'./test_maps/t2.fdf',
'./test_maps/elem-fract.fdf',
'./test_maps/pentenegpos.fdf',
'./test_maps/pnp_flat.fdf',
'./test_maps/50-4.fdf',
'./test_maps/10-70.fdf',
'./test_maps/elem-col.fdf',
'./test_maps/elem.fdf',
'./test_maps/10-2.fdf',
'./test_maps/julia.fdf',
'./test_maps/42.fdf',
'./test_maps/20-60.fdf',
'./test_maps/mars.fdf',
'./test_maps/plat.fdf',
'./test_maps/pyramide.fdf',
'./test_maps/pyra.fdf',
'./test_maps/pylone.fdf']

os.system("make");

for i in files:
	print('map is ', i)
	os.system('./fdf ' + i)
