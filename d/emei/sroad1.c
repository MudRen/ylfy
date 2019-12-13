// Room: /d/emei/sroad1.c  

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ��С���䣬��ڴ���������������ʱ�����һ�ʢ���ļ��ڣ���
¶���һ������������½����ޱȣ�ԶԶ��ȥ����һƬ������̺졣�ڴ��д�
�����ȵķֲ�����෿�ݣ�����һ����ʯ·������ͨ����ӵ����ģ��ڴ��
����һľ����д�������֡���Դ�塻��
LONG
	);

        set("exits", ([
              "north":__DIR__"sroad2",            
	]));
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

      if((int)room->add_temp("person_inside") > 0 )
    {
       return notify_fail("С���Ѿ��������ˣ������һ�ΰɣ�\n");        
     } 
   else {
        room->add_temp("person_inside",1);
     }
   } 
   
    message_vision("$N�⿪��������������С�ۣ�\n",me);
    me->set_temp("from_yanbohu",1);
    me->move(__DIR__"boat");
    return 1;
}
