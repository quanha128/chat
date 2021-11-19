package L7.sample2.pkg2;

// import java.util.ArrayList;
import java.util.HashMap;

import L7.sample2.pkg1.*;

public class MemberList{
    protected HashMap<String, Member> lst;

    public MemberList() {
        this.lst = new HashMap<String, Member>();
    }

    public void add(Member member) {
        this.lst.put(member.getId(), member);
    }

    public Member get(String id) {
        return this.lst.get(id);
    }

    public void remove(String id) {
        lst.remove(id);
    }

    public int count() {
        return this.lst.size();
    }
}
