inherit ROOM;
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����
LONG);   
        setup();
}
void init()
{
    object me;
    me = this_player();
    message_vision("��ֻ����ˮ��ͷ�������س��������������ǣ������ڼ��ٵ����³���\n", me);
    me->delete_temp("last_damage_from");
    me->set_temp("die_for","����");
    me->die();
}
