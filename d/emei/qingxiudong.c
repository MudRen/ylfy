// /d/emei/qingxiudong.c ���޶�
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "���޶�");
	set("long", @LONG
����һ����ɽ������ʯ��������ʮ�ֵĿ�����������һЩ�谵��������
��һ����ʯ̳����ʯ̳�ϰڷ���һ��ľ����������һЩ�鼮��һ��С��¯��
����¯�в��ϵ�Ʈ���������̡�ֻ�����鰸������һλʦ̫����ü�ʹ�����
�����������������ͷ��˼��
LONG
	);
	set("exits", ([ 
                "north" : __DIR__"zoulang5", 
		]));
	set("objects", ([ 
               CLASS_D("emei") + "/miejue" : 1,
     ]));

        setup();
	replace_program(ROOM);
}
