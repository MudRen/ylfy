//by enter
// modified by wind

inherit ROOM;

void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼��ϴ��·���ƽʱ��������ס������������
�¼���������������ͷ�Ե��������ƽʱһ�㶼û�ڼң���
�����������ȥ�ˡ�
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"zoulang1",
            ]));
	setup();
	replace_program(ROOM);
}
