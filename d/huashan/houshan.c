// houshan.c
// By Hop, 97.04.30
inherit ROOM;
void create()
{
    set("short", "��ɽ");
    set("long", @LONG
��������Ů���ɽ��һ��Сɽ�ȣ������˼����������й������죬��
��ɭɭ��ż����Զ�����������������������������㣬��ֱ������
���Լ�����������Դ��
��ԶԶ�Ŀ�������������С�ݣ����������Ѿ��þ�ÿס�����ˡ������ﲻ
���������������ô���أ�
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"siguoya",
    ]));
        set("objects", ([
                CLASS_D("huashan")+"/feng" : 1,
        ]));
    set("outdoors", "huashan" );
    set("no_magic",1);
    setup();
}
int valid_leave(object me, string dir)
{
    if ((me->query("family/family_name") == "��ɽ��") && (me->query("family/master_id") == "feng qingyang"))
    {
        me->move("/d/huashan/square");
        me->delete_temp("mark/steps");
        tell_object(me,"��ѭ�ŷ�����ָ����Ľݾ�һ���Ӿ������˻�ɽ���䳡��\n");
        return 1;
    }
    return 1;
}
