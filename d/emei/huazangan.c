// Room: /d/emei/huazangan.c ������ ������
// create by host dec,20 1997
inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕ��ҵĲؾ�����Ȼ����̫�󣬵����аڷ���������ܣ�
�����������������ĸ����鼮���ڿ�������һ�����ӣ�������һյ
�͵�(lamp)���ڵ��Ժ����Ƿ���һ���飬����Ҫ����ʱ��ȴ��������
һ���ա�
LONG
	);

	set("exits", ([
                "west": __DIR__"duguangtai",
//               "up": __DIR__"huazangan1",
	]));
        set("item_desc", ([
           "lamp" : "һյװ�����͵��͵�\n",  
             ])) ;

	set("objects",([
//		CLASS_D("shaolin") + "/dao-zheng" : 1,
	]));

	setup();

}
void init()
{

   add_action("do_light","light");
}
int do_light(string arg)
{

    object me,obj,obn;
    me=this_player();
    if (this_player()->query_temp("marks/light"))
		return notify_fail("���Ѿ����������ˣ���Ҫ��ʲô��\n");	
    if ( !arg || (arg != "lamp") )
       return notify_fail("��Ҫ��ʲô��\n");
    
   if (!(obj = present("fire stone", this_player())))
       return notify_fail("������ʲô�㰡����\n");

   obn = new("/d/emei/obj/dachengjing");
   obn->move(me);
   me->set_temp("marks/light", 1);
   message_vision("$N�ó���ʯ�������͵ơ�\n",me);
   message_vision("ֻ���͵��Ա߷���һ������˷𾭡���\n$N�ߵ���ǰ�����˷𾭡�\n",me);
 
   return 1;
  
}

