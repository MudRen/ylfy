// qingsonglin10.c ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
������������������ʧ�˷��򣬼��ʾ�������������о��Լ�����
������֮�У�ֻҪ�ߴ�һ��������������Σ�գ����г����˿־塣
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"qingsonglin"+(random(8)+6),
		"north" : __DIR__"qingsonglin"+(random(8)+6),
              "west" :__DIR__"qingsonglin"+(random(8)+6),
		"east" :__DIR__"qingsonglin"+(random(8)+6),

         ]));
	
	set("no_acc_drop",1);
	setup();
	replace_program(ROOM);
}
