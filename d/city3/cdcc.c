 
inherit ROOM;

void create()
{
        set("short", "��վ");
	set("long", @LONG
���ǳ���Ψһһ����վ�����δ��ʧ���κ��ż��ͻ�����Ҵ�
�ݼ�ʱ�����������һֱ�ܺá�
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"cdta",
	]));

	setup();
	replace_program(ROOM);
}

