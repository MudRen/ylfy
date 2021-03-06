// 地图坐标 

#define MAX_BIAN 6

inherit F_COLOR;

string *map_xy_num = ({"①", "②", "③", "④", "⑤", "⑥"});

int map_xy_msg(object me)
{
	object *ob;
	string name;
	int i, j, k;

	if ( !userp(me) )
		return 0;

	ob = all_inventory(environment(me));
	for ( i = 0; i < sizeof(ob); i++ )
	{
		if ( !ob[i]->is_character() || base_name(ob[i]) == "/clone/misc/corpse" )
			ob = ob - ({ob[i]});
	}

	printf("\n%s%-12s%-12s%-12s%-12s%-12s%-12s\n", "  ", "      ①", "      ②", "      ③", "      ④", "      ⑤", "      ⑥");
	printf("%s┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓\n", "  ");
	
	for (i = 0; i < MAX_BIAN; i++)
	{
		printf("%s", map_xy_num[i]);
		
		for (j = 0; j < MAX_BIAN; j++)
		{
			for (k = 0; k <  sizeof(ob); k++)
			{
				if ( ob[k]->query("xysys_map_xy/x") == j + 1 && ob[k]->query("xysys_map_xy/y") == i + 1 )
				{
					if ( ob[k] == me )
						name = sprintf(BBLU + HIG"%-10s"NOR, clean_color(ob[k]->name()));
					else if ( userp(ob[k]) )
						name = sprintf(HIY"%-10s"NOR, clean_color(ob[k]->name()));
					else
						name = clean_color(ob[k]->name());
					
					break;
				}
					
					name = "";
			}

			printf("%-12s", "┃" + name);
		}
		
		printf("%s", "┃\n");

		if ( i == MAX_BIAN - 1 )
			printf("%s┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛\n", "  ");
		else
			printf("%s┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫\n", "  ");
	}

	printf(HIG"【"HIM"温磬提示"HIG"】"HIB"『"HIY"非战斗中取消坐标行走及相关显示请输入："HIW"unset map_xy_msg"HIB"』\n"NOR);

	return 1;
}