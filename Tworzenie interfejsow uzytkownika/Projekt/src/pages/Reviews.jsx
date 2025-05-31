export default function Reviews() {
    const reviews = [
        {
            name: 'Adam Nowak',
            role: 'Właściciel warsztatu',
            comment:
                'System MCS znacznie ułatwił nam kontrolę nad stanami magazynowymi. Wreszcie wiemy, co mamy na stanie!',
            avatar: '🧔',
        },
        {
            name: 'Katarzyna Malec',
            role: 'Manager logistyki',
            comment:
                'Dzięki alertom o niskim stanie części nie musimy już sprawdzać wszystkiego ręcznie. Oszczędność czasu!',
            avatar: '👩‍💼',
        },
        {
            name: 'Tomasz Wójcik',
            role: 'Mechanik',
            comment:
                'Dodawanie nowych części jest szybkie i intuicyjne. Polecam każdemu, kto szuka prostego rozwiązania.',
            avatar: '👨‍🔧',
        },
        {
            name: 'Ewa Kaczmarek',
            role: 'Właściciel sklepu z częściami',
            comment:
                'Bardzo pomocny support i funkcjonalności dopasowane do realnych potrzeb branży.',
            avatar: '👩‍🔧',
        },
    ];

    return (
        <div className="max-w-6xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Opinie użytkowników</h1>

            <p className="text-lg text-gray-700 mb-12 text-center max-w-3xl mx-auto">
                Zobacz, co mówią nasi klienci o systemie zarządzania częściami samochodowymi.
            </p>

            <div className="grid md:grid-cols-2 gap-8">
                {reviews.map((review) => (
                    <div
                        key={review.name}
                        className="bg-white rounded-xl shadow-md p-6 hover:shadow-xl transition duration-300"
                    >
                        <div className="flex items-start gap-4">
                            <div className="text-5xl">{review.avatar}</div>
                            <div>
                                <h2 className="text-lg font-semibold text-gray-800">{review.name}</h2>
                                <p className="text-sm text-gray-500 mb-2">{review.role}</p>
                                <p className="text-gray-600 text-sm">{review.comment}</p>
                            </div>
                        </div>
                    </div>
                ))}
            </div>
        </div>
    );
}
