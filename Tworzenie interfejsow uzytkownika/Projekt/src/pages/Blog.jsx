export default function Blog() {
    const posts = [
        {
            title: 'Jak efektywnie zarządzać magazynem części?',
            date: '2025-05-10',
            excerpt:
                'Dowiedz się, jak zoptymalizować procesy magazynowe i uniknąć błędów w zarządzaniu zapasami.',
        },
        {
            title: 'Nowa funkcja: raporty stanów magazynowych',
            date: '2025-04-25',
            excerpt:
                'Wprowadziliśmy możliwość generowania raportów PDF z aktualnymi stanami i historią części.',
        },
        {
            title: 'Części zamienne – najczęstsze błędy przy zamówieniach',
            date: '2025-03-18',
            excerpt:
                'Sprawdź, jak uniknąć pomyłek przy dobieraniu części i jakie dane warto weryfikować.',
        },
        {
            title: 'Co nowego w wersji 1.5? Zobacz changelog!',
            date: '2025-02-02',
            excerpt:
                'Wersja 1.5 to lepsza wydajność, nowe alerty oraz integracje z zewnętrznymi bazami danych.',
        },
    ];

    return (
        <div className="max-w-6xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Blog</h1>

            <p className="text-lg text-gray-700 mb-12 text-center max-w-3xl mx-auto">
                Nowości, porady i aktualizacje dotyczące zarządzania częściami samochodowymi.
                Bądź na bieżąco z naszym systemem!
            </p>

            <div className="grid md:grid-cols-2 gap-8">
                {posts.map((post) => (
                    <article
                        key={post.title}
                        className="bg-white border-l-4 border-blue-500 rounded-lg p-6 shadow hover:shadow-xl transition-all duration-300"
                    >
                        <p className="text-sm text-blue-600 font-semibold mb-1">{new Date(post.date).toLocaleDateString()}</p>
                        <h2 className="text-xl font-bold text-gray-800 mb-2">{post.title}</h2>
                        <p className="text-gray-600 text-sm">{post.excerpt}</p>
                        <button className="mt-4 text-blue-600 hover:underline text-sm font-medium">
                            Czytaj więcej →
                        </button>
                    </article>
                ))}
            </div>
        </div>
    );
}
