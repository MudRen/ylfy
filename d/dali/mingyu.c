// Room: /d/dali/mingyu.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ18��3�롣

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��¥�䲻�ھ�������ȴ�Ǵ�������������¥�����������ľƣ�Ҳ����õľƣ�
����������Ů�ˣ�Ҳ������ζ����Ů�ˣ����������ķ���Ҳ����õķ���
���������ƣ�����һ�飬�ָ���һ�����ͽ��ң�
[1;35m
			��ɫ�ޱ�
[2;37;0m
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "���񷻷��棺
�������ɼд��κα�����¥��
�����Է���������С������Ϊû������������
�������ɼд��κ�ʳ���ˮ��¥��
������ҳ������������ѣ��໥�������ӣ�
������ܣ�������¥�洦�á�
��������ͷ������Խ�࣬���ܵ��ź�Խ�á�
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xidajie2",
  "south" : __DIR__"pingfeng",
]));

	set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/guinu" : 2,
]));

	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
	object *inv;
	int i;
        if( dir == "south" &&  ob = present("guinu",this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
			return notify_fail(ob->name()+"����Ц�������������񷻵Ĺ�أ����뿴�ƣ�\n");
			if((int)inv[i]->query("food_remaining") != 0)
			return notify_fail(ob->name()+"����Ц�������������񷻵Ĺ�أ����뿴�ƣ�\n");
			if((int)inv[i]->query("liquid/remaining") !=0)
			return notify_fail(ob->name()+"����Ц�������������񷻵Ĺ�أ����뿴�ƣ�\n");
			if((int)inv[i]->is_container()) 
//			if(check_container(inv[i]))
			return notify_fail(ob->name()+"����Ц�������������񷻵Ĺ�أ����뿴�ƣ�\n");
		}
        me->set("food",0);
        me->set("water",0);
        }
	return 1;
}

int check_container(object ob)
{
object *inv;
int i;
inv = all_inventory(ob);
 for(i=0; i<sizeof(inv); i++)
 {
                        if(inv[i]->query("weapon_prop"))
                        return 1;
                        if(inv[i]->query("food_remaining") != 0)
                        return 1;
                        if(inv[i]->query("liquid/remaining") !=0)
                        return 1;
                        if(inv[i]->is_container()) 
                        if(check_container(inv[i]))
                        return 1;
 }
return 0;
}
