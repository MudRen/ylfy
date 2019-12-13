//by zhm@silversand_mud
inherit ROOM;

void create()
{
        set("short", "�츮�㳡");
        set("long", @LONG
�����ǳɶ������ģ�ռ��Լ��Ķ����ɫ�Ĳ�ƺ����һ���
�ĵ�̺����������һ���������������ϰ����ˣ��������ǣ���
֪���ɶ�����ʷ���൱�ƾõġ������������˺ܶ࣬����������
Ħ����࣬���ο͡������ˡ����ˡ�С�������ˣ����ֺ�ߺ��
�������ڶ�����һ�����ַ����ľ���,������һ�ô�ɼ�����̸�
��ڣ��ݴ�����ǧ������䣬��
LONG
        );

        set("item_desc", ([
        "ɼ��"  :   "һ��֦Ҷïʢ�Ĵ�ɼ���������ƺ�������(climb)��ȥ��\n",
        "��ɼ��":   "һ��֦Ҷïʢ�Ĵ�ɼ���������ƺ�������(climb)��ȥ��\n",
        "��"    :   "һ��֦Ҷïʢ�Ĵ�ɼ���������ƺ�������(climb)��ȥ��\n",
        "tree"  :   "һ��֦Ҷïʢ�Ĵ�ɼ���������ƺ�������(climb)��ȥ��\n",
        ]));

        set("exits", ([
                "north" : __DIR__"beijie2",
                "south" : __DIR__"nanjie1",
                "west" : __DIR__"xijie2",
                "east" : __DIR__"dongjie1",                
        ]));
        set("outdoors","chengdu");
        set("objects",([
                  __DIR__"npc/xiaolanyan" : 3,
"/d/npc/shandian" : 1,             	
                  __DIR__"npc/laolanyan" : 1,
           ]));
      
        setup();
}

void init()
{
    add_action("do_climb", "climb");
}
 
int do_climb(string arg)
{
	object me, *obj;
	mixed *local;
	int i;
	
	local=localtime(time());
	
	/*if (local[6]==0 )
    return notify_fail("�����ϲ�������̦,��������û�����ϵ�!\n");*/

	me = this_player();

	if ( !objectp(me) ) return 0;
	
	if ( !arg || arg!="up" ) return notify_fail("��Ҫ���ĸ���������\n");
	if ( me->query_condition("killer") )
	{
		message("vision", 
			me->name() + "սս���������Ŵ�ɼ�����̸���ƨ��һŤһŤ��������������ҽ�һ����ˤ��������\n",
			environment(me), ({me}) );
		write("��սս���������Ŵ�ɼ�����̸������������һ��С��ˤ�˸�����ʺ��\n");
		return 1;
	}

	obj = deep_inventory(me);
	for ( i=0; i<sizeof(obj); i++ )
	{
		if ( obj[i]->is_character() && !obj[i]->is_corpse() )
		{
			message("vision", 
				me->name() + "սս���������Ŵ�ɼ�����̸���ƨ��һŤһŤ��������������ҽ�һ����ˤ��������\n",
				environment(me), ({me}) );
			write("��սս���������Ŵ�ɼ�����̸������������һ��С��ˤ�˸�����ʺ��\n");
			return 1;
		}
	}
	
	message("vision",
		me->name() + "սս���������Ŵ�ɼ�����̸���ƨ��һŤһŤ����������\n",
		environment(me), ({me}) );
	me->move("/d/city3/chatroom1.c");
	message("vision",
	me->name() + "�������������������\n", environment(me), ({me}) );
	return 1;
}