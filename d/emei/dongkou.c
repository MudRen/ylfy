// Room: /d/emei/dongkou.c ɽ����
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "ɽ����");
	set("long", @LONG
������һ��ɽ����ڣ���ɫ����̦��������ʯ�����������һ���ٲ�
ֱк�����Ĵ�����ʯ�Ϸ��������죬������ȥֻ��һ����ڣ�������
��
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong1",
	]));
	setup();
}
int valid_leave(object me,string dir)
{
    object *inv;
    int i;
    inv = all_inventory(this_player());
    for(i=sizeof(inv)-1; i>=0; i--) {
    if( inv[i]->is_character() && dir == "east")
        return notify_fail("����̫С�ˣ�ֻ�ܹ�����һ���˽�����\n");
    }
 return ::valid_leave(me,dir);
}