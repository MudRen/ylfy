// zijincheng.c�Ͻ��
// by arnzh 97.1.24 
inherit ROOM;
void create()
{
    set("short", "�Ͻ��");
    set("long", @LONG
�������ǰ��һ�����ۣ�����д�š��Ͻ�ǡ��������ɫ�Ĵ��֣���ש
���ߣ�Ժǽ����һ�˰��С�ġ������ٷ��ĸ����֡�Ժ�з�����������
������ͬ��ɫ�ĵ�ʿȷ���Ͻ����������о�������������������������һ
������С����
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "south" : __DIR__"liantai",
        "north" : __DIR__"xiaolu1",  
    ]));
//  set("objects", ([
//      CLASS_D("wudang") + "/zhike" : 1]));
    setup();
    replace_program(ROOM);
}
