//room: 
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
      "�����ǰ׻��õĳ��ȡ�����һƬ�Ǽ�,�����Ӹձ�ϴ��һ��,��غ�ʬ���в��̶ġ�\n"
 
     );
  set("exits",([
     "north" : __DIR__"baistep1",
      "south" : __DIR__"baihutang",
     ]));
  setup();
 replace_program(ROOM);
}
