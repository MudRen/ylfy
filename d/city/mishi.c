
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó������������
�˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ����������ǽ�ϣ���֪��
��������ʲ���ˣ������ǽ(wall)���ú�ɼľ���ģ�����������Ļ���
ǽ�������Ե���Щ��Ѱ����
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
"north" : __DIR__"gbxiaowu",     	
	]));
set("objects", ([
		]));
set("item_desc", ([
"wall" : "����һ���ú�ɼľ���ɵ�ǽ���ƺ����Դ���(break)����\n",
]) );
	setup();
	replace_program(ROOM);
}
