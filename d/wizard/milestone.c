inherit ITEM;

int do_read(string arg);

void create()
{
      

        set_name(RED "��"YEL"�������"RED"��" NOR, ({ "jinian bei","bei" }) );
        
        set("unit", "��");
        set("long", "����һ��������¼�������������ʯ���������Ž�����
������꣬���µ����ţ�ʯ�����ɡ����ϵ�����ȴ����
һ����һ����ʯ���Ͽ�¼�ţ�
��     һ��"CYN"����"HIY"����"NOR+CYN"���а�"NOR"
��     ����"YEL"����"HIM"����"NOR+YEL"���а�"NOR"
��     ����"BLU"����"HIC"����"NOR+BLU"���а�"NOR"
��     �ģ�"RED"����"HIW"����"NOR+RED"���а�"NOR"
��     �壺"WHT"����"HIR"����"NOR+WHT"���а�"NOR"

�������(read ���)���������ء�\n");
        
        set("material","steel");
        set_weight(8888888);
		set("no_get",1);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	string str;

	if(!arg || arg=="")
		return notify_fail("��Ҫ�Ķ���һ�����У�\n");
	
	switch(arg)
	{
		case "һ": arg ="rich";break;
		case "��": arg = "exp";break;
		case "��": arg = "neili";break;
		case "��": arg = "jingli";break;
		case "��": arg = "dushu";break;
		default : arg = "none";break;
	}
	
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");
	return 1;
}
