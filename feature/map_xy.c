// ��ͼ���� 

#define MAX_BIAN 6

inherit F_COLOR;

string *map_xy_num = ({"��", "��", "��", "��", "��", "��"});

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

	printf("\n%s%-12s%-12s%-12s%-12s%-12s%-12s\n", "  ", "      ��", "      ��", "      ��", "      ��", "      ��", "      ��");
	printf("%s�������������ש����������ש����������ש����������ש����������ש�����������\n", "  ");
	
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

			printf("%-12s", "��" + name);
		}
		
		printf("%s", "��\n");

		if ( i == MAX_BIAN - 1 )
			printf("%s�������������ߩ����������ߩ����������ߩ����������ߩ����������ߩ�����������\n", "  ");
		else
			printf("%s�ǩ����������贈���������贈���������贈���������贈���������贈����������\n", "  ");
	}

	printf(HIG"��"HIM"������ʾ"HIG"��"HIB"��"HIY"��ս����ȡ���������߼������ʾ�����룺"HIW"unset map_xy_msg"HIB"��\n"NOR);

	return 1;
}