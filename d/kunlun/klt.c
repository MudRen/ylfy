// Room: /d/kunlun/klt.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�����������̨�ˣ�����ӭ���������㿪ʼ�������ˡ�ֻ��������ѩ����
��ɽ�ڽ����¿������紿��������Ϧ������ʱ�ֱ�ò�����ƽ����˾���
�پ��Ŀ�������
LONG
        );
        set("outdoors", "klt");
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"klsj2",
  "northup" : __DIR__"zwf",
]));

        setup();
}
int valid_leave(object me, string dir)
{
    object boot;
    int damage=80-me->query_skill("dodge",1)/10;
    boot=me->query_temp("armor/boots");
    if (dir=="northup" && (!boot || boot->query("id")!="sandals")){
        if (damage<20){
            tell_object(me,HIW+"�����һ������������Σ�����ûˤ�ţ�\n"+NOR);
            return 1;
        }else
        me->receive_damage("qi",damage);
        me->receive_damage("jing",damage);
        return notify_fail(HIW+"�����һ����ˤ�˸��Ľų��죡\n"+NOR);
   }
   return 1;
}

