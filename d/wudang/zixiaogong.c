// zixiaogong.c������
// by arnzh 97.1.24 
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�������ǰ��һ�����ۣ�����д�š����������������ɫ�Ĵ��֣��ɴ�
���ھ����䵱������ˣ����ڽ�������������ˣ�������ͬ��ɫ�ĵ�ʿȷ��
�Ͻ����������о�����������������
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shibapan",
        "northup" : __DIR__"shijie61",  
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/zhike" : 1]));
    setup();
    replace_program(ROOM);
}
