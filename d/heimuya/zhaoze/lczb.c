
inherit ROOM;

void create()
{
	set("short", "���׽���");
	set("long", @LONG
��ɽ������һ��·��ֻ��ǰ��ŭ����ӿ��ˮ���ļ�������һ���󽭡���
��ɽʯ���������Ρ�룬�������ƣ����ǵ������׽��ϡ���������ɽʯ��С
·Ҳûһ�����߸߰˵͵��߳��߰���أ��ż���һ��Ұ�����������Ͻ�ʵ��
�ۡ�
LONG
);
	set("outdoors", "lczb");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"pubu",
  "south" : __DIR__"lczb1",
]));

	setup();
	replace_program(ROOM);
}
