// fu-houyuan.c ��Ժ
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ���ߵ��������ζ����Ũ���ˡ�����ϸһ��������
����һ��Բ���ţ��ƺ������Ǵ����ﴫ�����ġ��������������ߣ���
�Ǻ�Ա��������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southeast" : __DIR__"houhuayuan",
                "north" : __DIR__"fu-datang",
                "south" : __DIR__"fu-woshi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

