#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        object yuanwai = present("zhang yuanwai",environment(me));
        if(duration!=1) return 0;
        if(!yuanwai) yuanwai = find_living("zhang yuanwai");
        if(!yuanwai) {
                me->set("title",me->query("baktitle")?me->query("baktitle"):me->
query("title"));
                me->del_condition("in_baobiao");
                me->del_temp("baobiaod");
                return 1;
        }
        yuanwai->command("tell "+me->query("id")+"����ô���������ң��������ǲ�Ը
�����ˣ���Ҳ����ǿ��");
        me->set("title",me->query("baktitle")?me->query("baktitle"):me->query("t
itle"));
        me->del_condition("in_baobiao");
        me->del_temp("baobiaod");
        yuanwai->add("baobiao",-1);
        return 1;
}

