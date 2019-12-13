//room: juebi.c

inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","����");
  set("long",@LONG
ɽ������ͻȻ��ʧ��������ǰ��һ�����ڣ����¿�ȥ�������ƣ����
���޷�����ȵס���������ȥ(down)ʲôҲ���������Ա���һ��ʯ��(bei)��
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "southdown" : __DIR__"shandao2",
     ]));
  set("item_desc",([
      "bei" : "���ƻ�������ֹ���ӽ���,Υ��ɱ���⣡\n" ,
      "down" : "����û���κ�·�����벻ͨ����(jump)��ȥ��\n" ,
     ]));
  setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="down")
		return notify_fail("������벻ͨ��\n");

	if(!( room = find_object(__DIR__"xiaojin")) )
		room = load_object(__DIR__"xiaojin");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xiaojin.c' \n");
	message_vision("$N˫��һ�գ���Ȼ������ȥ��\n",me);
//       ��message("vision","��ֻ��һ����Ӱ���������\n", room);
        me->move(room);
        return 1;
}