
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    ���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�����������
������ա�������������Ҽ������������ڵ����������У��γ�������ɫ
�Ĺ�����ɷ�Ǻÿ������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У���
������ȥ��·�ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sslin-5",
  "south" : __FILE__,
  "east" : __DIR__"sslin-3",
  "west" : __FILE__,
]));
	set("objects", ([
//   "quest/skills2/wunon/non/nontian" : 5,	
	])); 
//	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
