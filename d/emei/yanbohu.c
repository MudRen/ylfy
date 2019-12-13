// Room: /d/emei/yanbohu.c �̲���


inherit ROOM;

void create()
{
	set("short", "�̲���");
	set("long", @LONG
������·�ľ�ͷ��һ�غ�ˮ��ס��ȥ·��ֻ����ˮ�������̲����ԣ�����
�������������ӻ��о�������������ů����Ĵ��紵�����ϣ�������������
��һ�������������֦������һ��һ������סҡ�������һ������������
�����̲���Ʈ����һҶС��(boat)��
LONG
	);

	set("exits", ([
                 "south":__DIR__"rongshulin2",
	]));
        set("item_desc", ([
           "boat" : "����һֻС�ۣ�����ʹ��(jump)����ȥ��\n",
             ])) ;
        set("outdoors", "emei");
	setup();
}
void init()
{
    add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    object me = this_player();
    object room;
    if (arg != "boat") return command("jump "+arg);
    if(!(room = find_object(__DIR__"boat")))
         room = load_object(__DIR__"boat");
     if(objectp(room))
    {

      if((int)room->add_temp("person_inside") > 10 ) //ԭ��0
    {
       return notify_fail("С���Ѿ��������ˣ������һ�ΰɣ�\n");        
     } 
   else {
        room->add_temp("person_inside",1);
     }
   } 
   
    message_vision("$N�⿪��������������С�ۣ�\n",me);
    me->set_temp("from_taoyuan",1);
    me->move(__DIR__"boat");
    return 1;
}
