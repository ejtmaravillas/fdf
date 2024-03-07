#include "fdf.h"

void	rotation_x(t_map_point *a, t_map_data *data)
{
	float	temp_z;
	float	temp_y;

	temp_z = a->z;
	temp_y = a->y;
	a->y = temp_y * cos(data->theta_x) + temp_z * sin(data->theta_x);
	a->z = -temp_y * sin(data->theta_x) + temp_z * cos(data->theta_x);
}

void	rotation_y(t_map_point *a, t_map_data *data)
{
	float	temp_x;
	float	temp_z;

	temp_x = a->x;
	temp_z = a->z;
	a->x = temp_x * cos(data->theta_y) + temp_z * sin(data->theta_y);
	a->z = -temp_x * sin(data->theta_y) + temp_z * cos(data->theta_y);
}
void	rotation_z(t_map_point *a, t_map_data *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = a->x;
	temp_y = a->y;
	a->x = temp_x * cos(data->theta_z) - temp_y * sin(data->theta_z);
	a->y = temp_x * sin(data->theta_z) + temp_y * cos(data->theta_z);
}