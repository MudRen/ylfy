//room: didao1.c
inherit ROOM;
void create()
{
  set("short","�ص�");
  set("long",
	"����һ���쳣�ľ�������,�������һ��,�����ʲô���������Ƶ�\n"
        "��������,�㲻���뵽���ƺ���ÿ�����䶼��������ɱ��,̫�ֲ���,\n"
        "���ܺ�����Ϣ���������һ���붼����������\n"
     );
  set("exits",([
      "east" : __DIR__"didao2",
      "west" : __DIR__"didao1",
      
      "south" : __DIR__"didao5",
     ]));
 setup();
 replace_program(ROOM);
}
