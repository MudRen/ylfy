// Room: /d/emei/jieyindian.c ������ ������

inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕ��ҵĽ���������Ƕ�����ר�ŽӴ���Щǰ�������������
������һЩ����ͬ���ĵط�����Ȼ������̫��ȴ�ܷ�����ֻ����һλʦ
̫����������Ӵ��������Ŀ��ˡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"basipan3",
	]));

	set("objects",([
	]));

	setup();
}
