int update_condition(object me, int duration)
{
me->receive_wound("jing", 200+random(100));
me->receive_wound("qi", 200+random(100));
              me->start_busy(2+random(2));
        me->set_temp("death_msg","���ڰ��޳���ȥ�����ˡ�\n");
        me->apply_condition("hell_zhua", duration - 1);
        if( (int)me->query("qi") < (int)me->query("max_qi")/4 )
                message_vision("$N���������п����ڰ��޳�����ǰ�ζ���\n", me);
        else if( (int)me->query("qi") < (int)me->query("max_qi")/2 )
                message_vision("$N����צ����Ҫ������һ����ȫ��鴤������\n", me);
        else 
          message_vision("$N����צ��һ���ʹ������ȫ��һ��鴤��\n", me);
        if( duration < 1 ) return 0;
return 1;
}

