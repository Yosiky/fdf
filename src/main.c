#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

inline void    put_pixel(const t_data *restrict data, int x, int y,
    unsigned int col)
{
    data->addr[y *(data->line_length >> 2u) + x] = col;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	//unsigned int color = 0;
	while (1)
	{
		for (int i = 1; i < 400; ++i)
		{
			for (int j = 1; j < 400; ++j)
				put_pixel(&img, i, j, 0x00FF0000);
		}
		//color += 100;
		//printf("%d\n", color);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	mlx_loop(mlx);
}
