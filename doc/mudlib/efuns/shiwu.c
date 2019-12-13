// Room
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
��һ�߽���,ֻ��������ֻ��һЩ�򵥵ļҾ�,һ�Ŵ������ߵ�ǽ��(wall)����
һ����Ů��ױͼ,��īϸ��,������Ů��Ϊ�Ը�,����һ��������Ƿ�.�����������
һ�Ȱ���(men),����ϸ�������ֲ��ˡ�
LONG
	);
	set("item_desc", ([
		"men" : "�������ƺ�ͨ��һ�����ҡ�\n",
                "wall": "���ǽ��������Щ�쳣,���벻����(push)һ���ء�\n",
	]));
        set("exits", ([
                "east"  : __DIR__"garden1",
        ]));
   	set("objects", ([
		__DIR__"npc/yang" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
        add_action("do_push", "push");
	if (present("yang lianting", environment(this_player())))
		delete("exits/northwest");
        if (query("exits/north"))
          { 
           message_vision("�������˴��˽���,ǽ�����Զ������ˡ�\n", this_player());	    
           delete("exits/north");
          }
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/northwest"))
		return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("dilao key", this_player())))
		return notify_fail("��ûԿ��,Ҳ����������\n");
	set("exits/northwest", __DIR__"tiemen");
	message_vision("$N��һ��Կ�״������ţ�����Կ��ȴ���������ˡ�\n", this_player());
	destruct(ob);
	return 1;
}
int do_push(string arg)
{	
	if (query("exits/north"))
		return notify_fail("���ǽ�Ѿ��ǿ���һ������,���߾Ϳ���,��ĥ���ˡ�\n");
	if (!arg || (arg != "wall" && arg != "north"))
		return notify_fail("�����ʲô�����ƶ����಻��ѽ��\n");
	set("exits/north", __DIR__"chlang2");
	message_vision("$N�����ѱ���ǽ���ƿ�һ�����ˡ�\n", this_player());
        call_out(do_close,0);
	return 1;
}
int do_close(void)
{
       if (query("exits/north"))
          { 
           message_vision("ʱ�䵢��̫��,ǽ�����Զ������ˡ�\n", this_player());	    
           delete("exits/north");
          }
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("yang lianting", environment(me))) && 
                     dir == "east" && living(present("yang lianting", environment(me))))
		return notify_fail("����ͤ��ס���㡣\n");
	return ::valid_leave(me, dir);
}
