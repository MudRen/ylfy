//room: didao2.c
inherit ROOM;
void create()
{
  set("short","�ص�");
  set("long",
	"��������һ���ص�,����������̫ƽ��,�������Եļ�յ�͵ƣ��谵�綹\n"
        "���ǿ���ȥǰ�����й�������Ҫ�Ǿ��ú���,���ڻ�ͷ���ǿ��Ե�,����\n"
        "���쳣���ľ�ȴҲ���󼤷�����ĺ�����,���ɷ����ֺ������,������\n"
        "���ɼ�.\n"
    );
  set("exits",([
//      "down" : __DIR__"mishi",
      "west" : __DIR__"didao1", 
      "south" : __DIR__"didao5",
     ]));
 setup();
 replace_program(ROOM);
}
