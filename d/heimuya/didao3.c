//room: didao5.c
inherit ROOM;
void create()
{
  set("short","�ص�");
  set("long",
	"\n"
        "��������,�㲻���뵽���ƺ���ÿ�����䶼��������ɱ��,��е����˽�\n"
        "��,Խ��Խ���ˡ�\n"
     );
  set("exits",([
      "east" : __DIR__"didao3",
      "west" : __DIR__"didao3",
      "north" : __DIR__"didao4",
      "south" : __DIR__"didao1",
     ]));
   
 setup();
 replace_program(ROOM);
}
