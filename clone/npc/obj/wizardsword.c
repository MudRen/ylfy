// longsword.c ����
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name(MAG "����֮��" NOR, ({ "sword", "jian" }));
    set_weight(9000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
	 set("icon", "10027");
        set("long", "����һ������֮������˵������������ɱ�Ķ�����\n");
        set("no_sell",1);
        set("material", "steel");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�$Nɲ�Ǽ�˫Ŀ���ࡣһ����ɱ�˵�����\n");
        set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
    }
    init_sword(200,2);
    setup();
}
void init()
{
    add_action("do_kill","kill");
}
int do_kill(string arg)
{
    object me,obj;
    if (!this_object()->query("equipped")) return 0;
    me=this_player();
    if (!userp(me) )
        return 0;
    if (!arg)   return 0;
    if(!objectp(obj = present(arg, environment(me))))
        return notify_fail("����û������ˡ�\n");
    if (userp(obj) ){
        message_vision("\n$N����$n�ȵ�����" 
        + RANK_D->query_rude(obj) + "�����ղ������������һ��\n\n", me, obj);
        tell_object(obj, HIR "�����Ҫ��" + me->name() 
            + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
        tell_object( me,
        HIR "\n\n�����Ҫ��ɱ�ˣ������ʮ���ڲ���ڣ�����������ˡ�\n\n\n" NOR);
        CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "����Ҫ��ɱ�ˡ�");
        me->start_busy(40);
        call_out("slow_suicide",5,me,40);
        return 1;
    }
}
protected int slow_suicide(object me,int sec)
{
    if (!me)    return 0;
    sec-=5;
    if (sec>1){
        tell_object(me, RED "\n\n\n�㻹��"+YEL+chinese_number(sec)+"��"+RED+"��ʱ�������ڡ�\t\t"+HIW+"���������ˣ��������˳�(quit)��Ϸ��\n\n\n" NOR);
        call_out("slow_suicide",5,me,sec);
    }else   call_out("do_suicide",1,me);
    return 1;
}
int do_suicide(object me)
{
    object link_ob;
    if (!me)    return 0;
    link_ob = me->query_temp("link_ob");
    if( !link_ob ) return 0;
    seteuid(ROOT_UID);
    write("�ðɣ�������:)��\n");
    tell_room(environment(me), me->name() +"��ɱ�ˣ���������Ҳ������������ˡ�\n", ({me}));
    me->save();
    destruct(me);
    return 0;
}
int query_autoload() { return 1; }